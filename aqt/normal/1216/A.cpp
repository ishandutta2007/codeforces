#include <bits/stdc++.h>

using namespace std;
string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N >> s;
    int cnt = 0;
    for(int i = 1; i<N; i+=2){
        if(s[i] != s[i-1]){
            continue;
        }
        else if(s[i] == 'a'){
            s[i] = 'b';
            cnt ++;
        }
        else{
            s[i] = 'a';
            cnt++;
        }
    }
    cout << cnt << endl;
    cout << s << endl;
}