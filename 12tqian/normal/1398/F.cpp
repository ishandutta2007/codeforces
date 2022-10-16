#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int a[MAX], run[MAX], ans[MAX];
char s[MAX];
int main(){
    int n; scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; ++i){
        if(s[i] == '0') a[i] = 0;
        else if(s[i] == '1') a[i] = 1;
        else a[i] = -1;
    }
    vector<pair<int, int>> blocks;
    int it1 = 0, it2 = 0;
    while(it1 != n){
        while(it2 < n - 1 && a[it1] == a[it2 + 1]) ++it2;
        blocks.emplace_back(it2 - it1 + 1, a[it1]);
        ++it2; it1 = it2;
    }
    for(int i = 0; i < (int) blocks.size(); ++i){
        if(blocks[i].second != -1) continue;
        if(i == 0) blocks[i].second = blocks[i + 1].second;
        else if(i == (int) blocks.size() - 1) blocks[i].second = blocks[i - 1].second;
        else if(blocks[i - 1].second == blocks[i + 1].second) blocks[i].second = blocks[i - 1].second;
    }
    vector<pair<int, int>> compress;
    it1 = 0; it2 = 0;
    while(it1 != (int) blocks.size()){
        int len = blocks[it1].first;
        while(it2 < (int) blocks.size() - 1 && blocks[it1].second == blocks[it2 + 1].second) it2++, len += blocks[it2].first;
        compress.emplace_back(len, blocks[it1].second);
        ++it2; it1 = it2;
    }
    for(auto block: compress){
        if(block.second == -1) continue;
        for(int len = 1; len <= block.first; len++) ans[len] += block.first / len;
    }
    int max_size = -1, bef = -2;
    int size = compress.size();
    for(int i = 0; i < size; i++){
        int len = compress[i].first;
        int type = compress[i].second;
        if(bef != -1 && type != -1){
            max_size = len;
            if(i != size - 1) max_size += compress[i + 1].first;
            for(int l = 1; l <= max_size; l++) run[l] = len % l;
        }
        else if(type == -1){
            for(int l = 1; l <= max_size; l++){
                if(run[l] + len >= l) run[l] += len, ans[l] += run[l] / l, run[l] %= l;
                else run[l] = len;
            }
            int add = 0;
            if(i != (int) size - 1) add += compress[i + 1].first;
            if(i != (int) size - 2) add += compress[i + 2].first;
            for(int l = max_size + 1; l <= len + add; ++l) run[l] = (len % l);
            max_size = len + add;
        }
        else{
            for(int l = 1; l <= max_size; ++l){
                if(run[l] + (len % l) >= l) run[l] += ((len % l) - l), ans[l]++;
                else run[l] += (len % l);
            }
        }
        bef = type;
    }
    for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}