#include<bits/stdc++.h>
using namespace std;

vector<string> Days;

int Besttake[500][501] = {0};


void f(int j)
{
    string s = Days[j];
    vector<int> lessons;
    for (int i = 0; i<s.length(); i++) if (s[i]=='1') lessons.push_back(i);
    int t = lessons.size();

    for (int i = 1; i<=t; i++)
    {
        if (i==1) Besttake[j][1]=1;
        else
        {
            Besttake[j][i] = 1000;
            for (int k = 0; k<=t-i; k++) Besttake[j][i] = min(Besttake[j][i], lessons[k+i-1]+1-lessons[k]);
        }
    }
    //cout<<t<<endl;
    for (int i = 0; i<=t/2; i++) swap(Besttake[j][i], Besttake[j][t-i]);
}

int answer[501] = {0};
void summi (int h)
{
    int answer1[501] = {0};
    for (int i = 0; i<=500; i++)
    {
        int minn = 1000000;
        for (int j = 0; j<=i; j++) minn = min(minn, answer[j]+Besttake[h][i-j]);
        answer1[i] = minn;
    }
    for (int i = 0; i<=500; i++) answer[i] = answer1[i];
}

int main()
{
int n, m, k;
cin>>n>>m>>k;
string s;
for (int i = 0; i<n; i++) {cin>>s; Days.push_back(s);}
for (int i = 0; i<n; i++) f(i);

for (int i = 0; i<n; i++) summi(i);
cout<<answer[k];


}