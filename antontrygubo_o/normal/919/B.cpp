#include<bits/stdc++.h>
using namespace std;

int sumdigits (int n)
{
    int sum = 0;
    while (n) {sum+=n%10; n/=10;}
    return sum;
}

vector<int> sum10;

int main()
{
int i = 0;
int n = 1;
while (i<10000)
{
    if (sumdigits(n)==10) {sum10.push_back(n); i++;}
    n+=9;
}
int k;
cin>>k;
cout<<sum10[k-1];
}