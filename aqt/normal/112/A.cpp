#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, t;
    cin >> s >> t;
    int N = s.size();
    for(int i = 0; i < N; i++){
        if(s[i] <= 'Z' && s[i] >= 'A'){
            s[i] += 'a' - 'A';
        }
        if(t[i] <= 'Z' && t[i] >= 'A'){
            t[i] += 'a' - 'A';
        }
        if(s[i] == t[i]){

        }
        else if(s[i] < t[i]){
            cout << -1 << "\n";
            return 0;
        }
        else{
            cout << 1 << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}