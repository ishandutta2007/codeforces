#include <bits/stdc++.h>

using namespace std;

string s;
int N;
vector<int> p[3];
int lft[3], rht[3];
vector<char> v;

int f(int t){
    //cout << " " << t << " " << lft[t] << " " << rht[t] << endl;
    if(lft[t] > rht[t]){
        return -1;
    }
    //cout << "rng: " << N-p[t][rht[t]]-(p[t][lft[t]]+1) << endl;
    return p[t][rht[t]]-(p[t][lft[t]])+1;
}

void upd(int t, int l, int r){
    while(lft[t] < p[t].size() && p[t][lft[t]] < l){
        lft[t]++;
    }
    while(rht[t] >= 0 && p[t][rht[t]] > r){
        rht[t]--;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    N = s.size();
    for(int i = 0; i<s.size(); i++){
        p[s[i]-'a'].push_back(i);
    }
    bool odd = 0;
    for(int i = 0; i<3; i++){
        rht[i] = p[i].size();
        rht[i]--;
    }
    for(int l = 0, r = N-1; l <= r; ){
        int idx = 0, c = f(0);
        for(int i = 1; i<=2; i++){
            //cout << f(i) << " " << i << endl;
            if(f(i) > c){
                idx = i;
                c = f(i);
            }
        }
        //cout << c << " " << l << " " << r << endl;
        if(c == -1){
            break;
        }
        v.push_back((char) (idx+'a'));
        if(lft[idx] == rht[idx]){
            odd = 1;
        }
        l = p[idx][lft[idx]]+1, r = p[idx][rht[idx]]-1;
        for(int i  =0; i<3; i++){
            upd(i,l, r);
        }
    }
    for(int i = 0; i<v.size(); i++){
        cout << v[i];
    }
    reverse(v.begin(), v.end());
    for(int i = odd; i<v.size(); i++){
        cout << v[i];
    }
}