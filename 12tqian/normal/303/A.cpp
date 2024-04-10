#include <bits/stdc++.h>
using namespace std;
static vector<int> a;
static vector<int> b;
int main(){
    int n;
    scanf("%d", &n);
    if(n%2 == 0){
        cout << -1 << endl;
        return 0;
    }
    if(n == 1){
        cout << 0 << endl;
        cout<< 0 <<endl;
        cout<< 0;
        return 0;
    }
    for(int i = 0; i<n; i++){
        cout<<i<< " ";
        a.emplace_back(i);
    }
    cout<<endl;
    cout<< n-2 << " ";
    cout<< n-1 << " ";
    b.emplace_back(n-2);
    b.emplace_back(n-1);
    for(int i = 0; i<n-2; i++){
        cout<< i<< " ";
        b.emplace_back(i);
    }
    cout<< endl;
    for(int i = 0; i<n; i++){
        cout<< (a[i] + b[i])%n << " ";
    }

    return 0;
}