#include <bits/stdc++.h>

using namespace std;

int T;
string s, t, p;
char arr[26][3];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> s >> t >> p;
        bool good = 1;
        for(int i = 0, j = 0; j<t.size() && i < s.size(); j++){
            if(s[i] == t[j]){
                i++;
            }
            if(j == (int) (t.size()) - 1 && i < s.size()){
                good = 0;
            }
        }
        for(int i =0; i<s.size(); i++){
            arr[s[i]-'a'][0]++;
        }
        for(int j = 0; j<t.size(); j++){
            arr[t[j]-'a'][1]++;
        }
        for(int k = 0; k<p.size(); k++){
            arr[p[k]-'a'][2]++;
        }
        for(int i = 0; i<26; i++){
            if(arr[i][0] <= arr[i][1] && arr[i][0] + arr[i][2] >= arr[i][1]){

            }
            else{
                good = 0;
            }
            arr[i][0] = arr[i][1] = arr[i][2] = 0;
        }
        if(good){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}