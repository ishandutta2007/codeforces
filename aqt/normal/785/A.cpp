#include <bits/stdc++.h>

using namespace std;

int N;
string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int ans = 0;
    while(N--){
        cin >> s;
        if(s == "Tetrahedron") ans += 4;
        if(s =="Cube") ans += 6;
        if(s == "Octahedron") ans += 8;
        if(s =="Dodecahedron") ans += 12;
        if(s == "Icosahedron") ans += 20;
    }
    cout << ans << endl;
}