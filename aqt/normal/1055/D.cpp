#include <bits/stdc++.h>

using namespace std;

int N, M = 6000;
long long sd = 131, MOD = 1261732613;
long long hsh[6005][3005];
long long pows[6005];
long long hsh1, hsh2;
int rept[3005];
int cl, cr, cxl, cxr;
string s[3005], t[3005];
string a, b;

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> s[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> t[i];
    }
    pows[0] = 1;
    for(int i = 1; i<=M; i++){
        pows[i] = mult(pows[i-1], sd);
    }
    int idx = 0;
    for(int i = 1; i<=N; i++){
        if(s[i] != t[i]){
            int l = 0, r = s[i].size()-1;
            cl = 0, cr = s[i].size()-1;
            for(; l <= r; l++){
                if(s[i][l] != t[i][l]){
                    break;
                }
            }
            for(; r>=l; r--){
                if(s[i][r] != t[i][r]){
                    break;
                }
            }
            cxl = l, cxr = r;
            for(int k = l; k<=r; k++){
                a.push_back(s[i][k]);
                b.push_back(t[i][k]);
            }
            idx = i;
            break;
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=s[i].size(); j++){
            hsh[i][j] = add(mult(hsh[i][j-1], sd), s[i][j-1]);
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=t[i].size(); j++){
            hsh[i+N][j] = add(mult(hsh[i+N][j-1], sd), t[i][j-1]);
        }
    }
    for(int j = 1; j<=a.size(); j++){
        hsh1 = add(mult(hsh1, sd), a[j-1]);
    }
    for(int j = 1; j<=b.size(); j++){
        hsh2 = add(mult(hsh2, sd), b[j-1]);
    }
    for(int i = 1; i<=N; i++){
        if(s[i] != t[i]){
            int l = 0, r = s[i].size()-1;
            for(; l<=r; l++){
                if(s[i][l] != t[i][l]){
                    break;
                }
            }
            for(; r>=l; r--){
                if(s[i][r] != t[i][r]){
                    break;
                }
            }
            if(r-l+1 != a.size() ||
               sub(hsh[i][r+1], mult(hsh[i][l], pows[r-l+1])) != hsh1 ||
               sub(hsh[i+N][r+1], mult(hsh[i+N][l], pows[r-l+1])) != hsh2){
                cout << "NO" << endl;
                return 0;
            }
            rept[i] = r+1;
            int lft = cxl;
            for(int k = cxl-1, c = l-1; k>=cl && c>=0; k--, c--){
                if(s[i][c] != s[idx][k] || t[i][c] != t[idx][k]){
                    break;
                }
                lft = k;
            }
            cl = lft;
            int rht = cxr;
            for(int k = cxr+1, c = r+1; k<=cr && c<s[i].size(); k++, c++){
                if(s[i][c] != s[idx][k] || t[i][c] != t[idx][k]){
                    break;
                }
                rht = k;
            }
            cr = rht;
        }
    }
    int delta = cr-cxr;
    for(int i = 1; i<=N; i++){
        rept[i] += delta;
    }
    a.clear(), b.clear();
    hsh1 = hsh2 = 0;
    for(int i = cl; i<=cr; i++){
        a.push_back(s[idx][i]);
        b.push_back(t[idx][i]);
    }
    for(int j = 1; j<=a.size(); j++){
        hsh1 = add(mult(hsh1, sd), a[j-1]);
    }
    for(int j = 1; j<=b.size(); j++){
        hsh2 = add(mult(hsh2, sd), b[j-1]);
    }
    for(int i = 1; i<=N; i++){
        if(s[i] == t[i]){
            for(int j = a.size(); j<=s[i].size(); j++){
                if(sub(hsh[i][j], mult(hsh[i][j-a.size()], pows[a.size()])) == hsh1){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        else{
            for(int j = a.size(); j<=s[i].size(); j++){
                if(sub(hsh[i][j], mult(hsh[i][j-a.size()], pows[a.size()])) == hsh1){
                    if(rept[i] != j){
                        cout << "NO" << endl;
                        return 0;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    cout << a << endl;
    cout << b << endl;
}