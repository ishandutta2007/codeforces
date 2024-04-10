#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    set <int> s;
    s.insert(-1);
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if (s.find(x - 1) == s.end()){
            cout<<i + 1<<endl;
            return 0;
        }
        s.insert(x);
    }
    cout<<-1<<endl;
}