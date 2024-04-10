#include<bits/stdc++.h>
using namespace std;

const long long N = 1000000009;

long long gcd (long long a, long long b, long long &x, long long &y)
{
    if (a==0)
    {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b%a, a, x1, y1);
    x = y1-(b/a)*x1;
    y = x1;
    return d;
}


long long power(long long x, long long k)
{
    if (k==0) return 1;
    if (k%2==0) return (power(x, k/2)*power(x, k/2))%N;
    if (k%2==1) return (power(x, k-1)*x)%N;
}

int main()
{
long long n, a, b, k;
cin>>n>>a>>b>>k;
string s;
cin>>s;
int sign[k] = {0};
for (int i = 0; i<k; i++) {sign[i]=-1; if (s[i]=='+') sign[i]=1;}

long long r_a[k];
r_a[0] = 1;
for (int i = 1; i<k; i++) r_a[i] = (r_a[i-1]*a)%N;

long long r_b[k];
r_b[0] = 1;
for (int i = 1; i<k; i++) r_b[i] = (r_b[i-1]*b)%N;

//for (int i = 0; i<k; i++) cout<<i<<' '<<r_a[i]<<' '<<r_b[i]<<endl;


long long t = (n+1)/k;

long long a1 = (r_a[k-1]*a)%N;
long long b1 = (r_b[k-1]*b)%N;


long long A1 = power(a1, t-1);
long long B1 = power(b1, t-1);




long long part1 = 0;
for (int i = 0; i<k; i++)
{
    part1=(part1+sign[i]*r_a[k-1-i]*r_b[i])%N;
    //cout<<"!"<<i<<' '<<part1<<endl;
}

long long part2 = 0;



    long long gopa = (A1*a1)%N;
    gopa = (gopa-B1*b1)%N;
    //cout<<gopa<<endl;
    long long gopa1 = a1-b1;
    while (gopa1<0) gopa1+=N;

    
    if (gopa1==0)
    {
        part2 = (t*A1)%N;
    }
    
    else
    {long long x, y;
    gcd(gopa1, N, x, y);
    part2=(gopa*x)%N;}







long long result = (part1*part2)%N;
//cout<<part1<<' '<<part2<<endl;
while (result<0) result+=N;
cout<<result;





}