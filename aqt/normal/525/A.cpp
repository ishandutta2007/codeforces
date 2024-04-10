#include <bits/stdc++.h>

using namespace std;

char c[26];
int N;
string s;

int main(){
    cin >> N;
    cin >> s;
    N--;
    int cnt = 0;
    for(int i =0; i<2*N; i+=2){
        c[s[i]-'a']++;
        if(c[s[i+1]-'A']){
            c[s[i+1]-'A']--;
        }
        else{
            cnt++;
        }
    }
    cout << cnt << endl;
}