#include <bits/stdc++.h>

using namespace std;

string s;
long long x1, y1, x2, y2;
int N;
long long netx[100005], nety[100005];

int main(){
    cin >> x1 >> y1 >> x2 >> y2 >> N >> s;
    long long x = x2-x1, y = y2-y1;
    for(int i = 0; i<N; i++){
        netx[i+1] = netx[i];
        nety[i+1] = nety[i];
        if(s[i] == 'L'){
            netx[i+1]--;
        }
        if(s[i] == 'R'){
            netx[i+1]++;
        }
        if(s[i] == 'U'){
            nety[i+1]++;
        }
        if(s[i] == 'D'){
            nety[i+1]--;
        }
    }
    long long l = 0, r = 10000000000000000, ans = -1;
    while(l <= r){
        long long mid = (l+r)>>1;
        long long crntx = netx[N]*(mid/N) + netx[mid%N], crnty = nety[N]*(mid/N) + nety[mid%N];
        if(abs(x-crntx) + abs(y-crnty) <= mid){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}