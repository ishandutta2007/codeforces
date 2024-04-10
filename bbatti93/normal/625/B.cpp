#include <bits/stdc++.h>
using namespace std;

vector<int> create_KMP_table(string pattern){
    vector<int> res(pattern.size(), -1);
    int j=-1;
    for(int i=1; i<pattern.size(); i++){
        while(j > -1 && pattern[j+1] != pattern[i]) j = res[j];
        if(pattern[j+1] == pattern[i]) j++;
        res[i] = j;
    }
    return res;
}

int hanyszor=0;

char* find(const string& pattern, const vector<int>& table, char* i){
    int j = -1;
    while(1){
        ++hanyszor;
        //cout<<*i<<" "<<j<<endl;
        if(j == pattern.size()-1) return i;
        if(*i == '-') return NULL;
        if(pattern[j+1] == *(i)){
            i++;
            j++;
        }
        else{
            if(j > -1) j = table[j];
            else i++;
        }
    }
}

string pattern, large_string;

vector<int> table;

int solve(char* i){
    int res = 0;
    i = find(pattern,table, i);
    while(i != NULL){
        res++;
        i = find(pattern,table, i);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("be.txt", "r", stdin);
    cin>>large_string>>pattern;

    large_string.push_back('-');
    table = create_KMP_table(pattern);

    cout<<solve(&large_string[0]);
}