#include <bits/stdc++.h>
using namespace std;
static map<long long, long long> c;
static map<long long, long long> r;
bool rcontains(long long x){
    map<long long, long long>::iterator it = r.find(x);
    if(it!= r.end()){
        return true;
    }
    return false;
}
bool ccontains(long long x){
    map<long long, long long>::iterator it = c.find(x);
    if(it!= c.end()){
        return true;
    }
    return false;
}
int main(){
    long long rsize = 0;
    long long csize = 0;
    long long n, m;
    vector<long long> ans;
    cin >> n >> m;
    for(long long i = 0; i<m; i++){
        long long row, col;
        cin >> row >> col;
        if(!rcontains(row)){
            r[row] = 1;
            rsize += 1;
        }
        if(!ccontains(col)){
            c[col] = 1;
            csize += 1;
        }
        long long fin = rsize*n + csize*n - rsize*csize;
        ans.emplace_back(fin);
    }
    for(long long i: ans){
        cout << n*n - i << " " ;
    }
    return 0;
}