#include <bits/stdc++.h>

using namespace std;

struct Node{
    int cnt;
    Node* lft;
    Node* rht;
    Node(){
        cnt = 0;
        lft = NULL;
        rht = NULL;
    }
};

Node* rt = new Node();
long long pre = 0;
int N, K;

int gsz(Node *n){
    if(n == NULL){
        return 0;
    }
    else{
        return n->cnt;
    }
}

void ins(int idx, int v, Node *&n){
    if(n == NULL){
        n = new Node();
    }
    n->cnt++;
    if(idx == -1){
        return;
    }
    if((1<<idx)&v){
        ins(idx-1, v, n->rht);
    }
    else{
        ins(idx-1, v, n->lft);
    }
}

int query(int idx, int v, Node *n){
    if(n == NULL){
        return 0;
    }
    if(idx == -1){
        return gsz(n);
    }
    if((1<<idx)&K){
        if(v&(1<<idx)){
            return query(idx-1, v, n->lft);
        }
        else{
            return query(idx-1, v, n->rht);
        }
    }
    else{
        if(v&(1<<idx)){
            return gsz(n->lft) + query(idx-1, v, n->rht);
        }
        else{
            return gsz(n->rht) + query(idx-1, v, n->lft);
        }
    }
}

int main(){
    cin>> N >> K;
    ins(30, 0, rt);
    long long ans = 0;
    for(int i =1 ; i<=N; i++){
        int n;
        cin >> n;
        pre ^= n;
        ans += query(30, pre, rt);
        ins(30, pre, rt);
    }
    cout << ans <<endl;
}