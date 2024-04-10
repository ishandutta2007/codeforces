#include <bits/stdc++.h>

using namespace std;

int L, N;
string s;
vector<int> pos[26];
int arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> L >> s;
    N = s.size();
    for(int i = 0; i<N; i++){
        pos[s[i]-'a'].push_back(i);
    }
    vector<char> ans;
    for(int c = 0; c<26; c++){
        int sum = 0;
        for(int n = 0; n<L-1; n++){
            if(s[n]-'a' <= c){
                sum++;
            }
        }
        bool b = 1;
        for(int r = L-1, l = 0; r<N; r++,l++){
            sum += (s[r]-'a' <= c);
            if(!sum){
                b = 0;
                break;
            }
            sum -= (s[l]-'a' <= c);
        }
        if(b){
            sum = 0;
            int cnt = 0;
            for(int n = 0; n<L-1; n++){
                if(s[n]-'a'+1 <= c){
                    sum++;
                }
            }
            for(int r = L-1, l = 0; r<N; r++, l++){
                sum += (s[r]-'a'+1 <= c);
                //cout << r << " " << sum << endl;
                if(!sum){
                    int idx = *(--upper_bound(pos[c].begin(), pos[c].end(), r));
                    cnt++;
                    while(r < idx+L){
                        sum += (s[r]-'a'+1 <= c);
                        //cout << r << " " << sum << endl;
                        sum -= (s[l]-'a'+1 <= c);
                        r++, l++;
                    }
                    r--, l--;
                    continue;
                }
                sum -= (s[l]-'a'+1 <= c);
            }
            vector<char> ans;
            for(char k = 'a'; k<'a'+c; k++){
                int n = pos[k-'a'].size();
                while(n--){
                    ans.push_back(k);
                }
            }
            while(cnt--){
                ans.push_back((char) ('a'+c));
            }
            for(char t : ans){
                cout << t;
            }
            return 0;
        }
    }
}