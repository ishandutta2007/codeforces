#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

typedef complex<double> base;
void fft (vector<base> & a, bool invert) {
int n = (int) a.size();
if (n == 1) return;
vector<base> a0 (n/2), a1 (n/2);
for (int i=0, j=0; i<n; i+=2, ++j) {
a0[j] = a[i];
a1[j] = a[i+1];
}
fft (a0, invert);
fft (a1, invert);
double ang = 2*M_PI/n * (invert ? -1 : 1);
base w (1), wn (cos(ang), sin(ang));
for (int i=0; i<n/2; ++i) {
a[i] = a0[i] + w * a1[i];
a[i+n/2] = a0[i] - w * a1[i];
if (invert)
a[i] /= 2, a[i+n/2] /= 2;
w *= wn;
}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> &
res) {
vector<base> fa (a.begin(), a.end()), fb (b.begin(), b.end());
size_t n = 1;
while (n < max (a.size(), b.size())) n <<= 1;
n <<= 1;
fa.resize (n), fb.resize (n);
fft (fa, false), fft (fb, false);
for (size_t i=0; i<n; ++i)
fa[i] *= fb[i];
fft (fa, true);
res.resize (n);
for (size_t i=0; i<n; ++i)
res[i] = int (fa[i].real() + 0.5);
}

void solve(string s)
{
    int n = s.length();
    vector<bool> good (n+1, 1);
    vector<int> Vs(n, 0);
    for (int i = 0; i<n; i++) if (s[i]=='V') Vs[i] = 1;
    vector<int> Ks(n, 0);
    for (int i = 0; i<n; i++) if (s[i]=='K') Ks[n-1-i] = 1;
    vector<int> res;
    multiply(Vs, Ks, res);
    vector<int> goods;
    for (int i = 0; i<res.size(); i++)
    {
        if (res[i]!=0) good[fabs(i-n+1)] = 0;
    }
    for (int j = 1; j<=n; j++)
    {
        for (int k = 2*j; (k<=n&&good[j]!=0); k+=j) if (good[k]==0) good[j] = 0;
    }
    int counter = 0;
    for (int i = 1; i<=n; i++) counter+=good[i];
    cout<<counter<<endl;
    for (int i = 1; i<=n; i++) if (good[i]==1) cout<<i<<' ';
    cout<<endl;
    
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    int temp;
    string my;
    for (int i = 0; i<t; i++)
    {
        cin>>temp;
        cin>>my;
        solve(my);
    }
    
    

}