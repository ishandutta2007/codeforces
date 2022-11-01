#include <bits/stdc++.h>
using namespace std;
// trie: each node has nxt[2], cnt, val
typedef struct{
    int nxt[2];
    int cnt;
    int val;
} node;
vector<node> trie;
void add(int x){
    int nds = 0;
    for(int i=29;i>=0;i--){
        trie[nds].cnt++;
        if(x&(1<<i)){
            if(trie[nds].nxt[1] == -1){
                node tmp;
                tmp.nxt[0] = tmp.nxt[1] = -1;
                tmp.cnt = 0;
                tmp.val = trie[nds].val + (1<<i);
                trie.push_back(tmp);
                trie[nds].nxt[1] = trie.size() - 1;
            }
            nds = trie[nds].nxt[1];
        }
        else{
            if(trie[nds].nxt[0] == -1){
                node tmp;
                tmp.nxt[0] = tmp.nxt[1] = -1;
                tmp.cnt = 0;
                tmp.val = trie[nds].val;
                trie.push_back(tmp);
                trie[nds].nxt[0] = trie.size() - 1;
            }
            nds = trie[nds].nxt[0];
        }
    }
    trie[nds].cnt++;
}
void init_trie(){
    node tmp;
    tmp.nxt[0] = tmp.nxt[1] = -1;
    tmp.cnt = 0;
    tmp.val = 0;
    trie.push_back(tmp);
}
int solve(int x){
    int nds = 0;
    for(int i=29;i>=0;i--){
        trie[nds].cnt--;
        if(x&(1<<i)){
            if(trie[nds].nxt[1] == -1 || trie[trie[nds].nxt[1]].cnt == 0) nds = trie[nds].nxt[0];
            else nds = trie[nds].nxt[1];
        }
        else{
            if(trie[nds].nxt[0] == -1 || trie[trie[nds].nxt[0]].cnt == 0) nds = trie[nds].nxt[1];
            else nds = trie[nds].nxt[0];
        }
    }
    trie[nds].cnt--;
    return trie[nds].val;
}
int A[300000], N;
int main(){
    init_trie();
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    for(int i=0;i<N;i++){
        int P;
        scanf("%d",&P);
        add(P);
    }
    for(int i=0;i<N;i++){
        printf("%d ",A[i] ^ solve(A[i]));
    }
}