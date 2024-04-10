#include <bits/stdc++.h>

using namespace std;

int N;
string s;
bool room[10];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> s;
    for(int i = 0; i<N; i++){
        if(s[i] == 'L'){
            for(int j = 0; j<10; j++){
                if(!room[j]){
                    room[j] = 1;
                    break;
                }
            }
        }
        else if(s[i] == 'R'){
            for(int j = 9; j>=0; j--){
                if(!room[j]){
                    room[j] = 1;
                    break;
                }
            }
        }
        else{
            room[s[i]-'0'] = 0;
        }
    }
    for(int i = 0; i<10; i++){
        cout << room[i];
    }
}