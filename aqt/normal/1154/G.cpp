#include <bits/stdc++.h>

using namespace std;

int N, M = 10000000;
pair<int, int> fre[10000005];
long long arr[1000005];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        arr[i] = n;
        if(fre[n].first){
            fre[n].second = i;
        }
        else{
            fre[n].first = i;
        }
    }
    long long ans = LLONG_MAX, p1 = 0, p2 = 0;
    for(long long i = 1; i<=M; i++){
        pair<int, int> p;
        for(long long j = i; j<=M && !p.second; j+=i){
            if(fre[j].first){
                if(p.first){
                    p.second = fre[j].first;
                }
                else{
                    p.first = fre[j].first;
                }
            }
            if(fre[j].second){
                p.second = fre[j].second;
            }
        }
        if(p.second && arr[p.first] * arr[p.second] / i < ans){
            ans = arr[p.first] * arr[p.second] / i;
            p1 = p.first, p2 = p.second;
        }
    }
    if(p1 > p2){
        swap(p1, p2);
    }
    cout << p1 << " " << p2 << endl;
}