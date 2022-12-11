#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int a;
    cin >> a;
    int tot = 0, totb = a;
    tot += a;
    v.push_back(1);
    for(int i = 2; i<=N; i++){
        int n;
        cin >> n;
        tot += n;
        if(2*n <= a){
            totb += n;
            v.push_back(i);
        }
    }
    if(totb*2 > tot){
        cout << v.size() << "\n";
        for(int n : v){
            cout << n << " ";
        }
    }
    else{
        cout << 0 << "\n";
    }
}