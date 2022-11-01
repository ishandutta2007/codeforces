#include <bits/stdc++.h>
using namespace std;
string s,t;
int bc[2][100002], aa[2][100002];
string ans;
char solve(int a, int b, int c, int d){
    int tmp1 = (aa[0][b] == -1) ? 0 : b - max(aa[0][b],a) + 1;
    int tmp2 = (aa[1][d] == -1) ? 0 : d - max(aa[1][d],c) + 1;
    if(tmp1 < tmp2) return '0';
    int tmp3 = bc[0][b] - bc[0][a-1];
    int tmp4 = bc[1][d] - bc[1][c-1];
    if(tmp1 == b-a+1 && tmp4 != 0){
        if(tmp1-1 < tmp2) return '0';
        tmp1 = tmp2;
        tmp3 += 2;
    }
    if((tmp1-tmp2)%3) tmp3 += 2;
    if(tmp3 > tmp4) return '0';
    if((tmp4-tmp3)%2) return '0';
    return '1';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    aa[0][0] = -1;
    aa[1][0] = -1;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'A'){
            aa[0][i+1] = (aa[0][i] == -1) ? i+1 : aa[0][i];
            bc[0][i+1] = bc[0][i];
        }
        else{
            aa[0][i+1] = -1;
            bc[0][i+1] = bc[0][i] + 1;
        }
    }
    for(int i=0;i<t.length();i++){
        if(t[i] == 'A'){
            aa[1][i+1] = (aa[1][i] == -1) ? i+1 : aa[1][i];
            bc[1][i+1] = bc[1][i];
        }
        else{
            aa[1][i+1] = -1;
            bc[1][i+1] = bc[1][i] + 1;
        }
    }
    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        ans += solve(a,b,c,d);
    }
    cout << ans << "\n";
}