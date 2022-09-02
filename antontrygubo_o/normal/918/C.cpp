#include<bits/stdc++.h>
using namespace std;

int a[5000][5000] ={0};

int main()
{

string s;
cin>>s;
int n = s.length();
for (int i = 0; i<n; i++)
for (int j = i+1; j<n; j++)
{
    a[i][j] = 1;
}
int left[n+1] = {0};
int right[n+1] = {0};
int joker[n+1] = {0};

for (int i = 0; i<n; i++)
{
    left[i+1] = left[i];
    right[i+1] = right[i];
    joker[i+1] = joker[i];
if (s[i]=='(') left[i+1]++;
if (s[i]==')') right[i+1]++;
if (s[i]=='?') joker[i+1]++;
}

for (int i = 0; i<n; i++)
{

int j = i;
while ((j<n)&&(left[j+1]-left[i]+joker[j+1]-joker[i]>=right[j+1]-right[i])) j++;
for (int g = j; g<n; g++) a[i][g] = 0;
//cout<<i<<' '<<j<<endl;
}
//cout<<endl;
for (int i = n-1; i>=0; i--)
{

int j = i;
while ((j>=0)&&(right[i+1]-right[j]+joker[i+1]-joker[j]>=left[i+1]-left[j])) j--;
for (int g = j; g>=0; g--) a[g][i] = 0;
//cout<<i<<' '<<j<<endl;
}

int summ = 0;
for (int i = 0; i<n; i++)
for (int j = i+1; j<n; j++)
if ((j-i)%2==1) summ+=a[i][j];
cout<<summ<<endl;
//for (int i = 0; i<n; i++) cout<<left[i]<<' ';
//cout<<endl;

}