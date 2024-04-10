#include <bits/stdc++.h>

using namespace std;

int lps[500005];
string s, p;
int cnt[2];

int main(){
    cin >> s >> p;
    for(int i = 0; i<s.size(); i++){
        cnt[s[i]-'0']++;
    }
    lps[1] = 1;
    for(int i = 2, j = 1; i<=p.size(); ){
        if(p[i-1] == p[j-1]){
            lps[i++] = ++j;
        }
        else if(j != 1){
            j = lps[j-1];
        }
        else{
            lps[i] = 1;
            i++;
        }
    }
    int counter = s.size(), i = 1;
    while(counter--){
        if(cnt[p[i-1]-'0']){
            printf("%c", p[i-1]);
            cnt[p[i-1]-'0']--;
        }
        else{
            if(p[i-1] == '1'){
                printf("%c", '0');
            }
            else{
                printf("%c", '1');
            }
            cnt[(p[i-1]-'0'+1)%2]--;
        }
        i++;
        if(i == p.size()+1){
            i = lps[i-1];
        }
    }
}