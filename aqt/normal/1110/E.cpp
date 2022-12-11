#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> d1, d2;

int main(){
    cin >> N;
    int lst = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        d1.push_back(n-lst);
        lst = n;
    }
    lst = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        d2.push_back(n-lst);
        lst = n;
    }
    sort(d1.begin()+1, d1.end());
    sort(d2.begin()+1, d2.end());
    for(int i = 0; i<d1.size(); i++){
        if(d1[i] != d2[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}