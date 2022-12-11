#include <bits/stdc++.h>

using namespace std;

long long N, K, A, B;
vector<int> tot;

long long rec(vector<int> vec, long long l, long long r){
    if(vec.empty()){
        return A;
    }
    if(r-l == 0){
        return B*vec.size();
    }
    long long mid = (l+r)/2;
    assert(mid-l+1 == r-mid);
    vector<int> lft, rht;
    for(int n : vec){
        if(n <= mid){
            lft.push_back(n);
        }
        else{
            rht.push_back(n);
        }
    }
    return min(rec(lft, l, mid) + rec(rht, mid+1, r), B*vec.size()*(r-l+1));
}

int main(){
    cin >> N >> K >> A >> B;
    for(int i =1; i<=K; i++){
        int n;
        cin >> n;
        tot.push_back(n);
    }
    cout << rec(tot, 1, 1<<N) << endl;
}