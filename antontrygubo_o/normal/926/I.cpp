#include<bits/stdc++.h>
using namespace std;

int f(string s)
{
    int answer = 0;
    answer += 600*(int(s[0])-48);
    answer += 60*(int(s[1])-48);
    answer += 10*(int(s[3])-48);
    answer += (int(s[4])-48);
    return answer;
}

string s(int a)
{
    string answer;
    answer.clear();
    answer+=char(a/600 + 48);
    a=a%600;
    answer+=char(a/60 + 48);
    a=a%60;
    answer+=':';
    answer+=char(a/10 + 48);
    a=a%10;
    answer+=char(a + 48);
    return answer;
}

int timer[2880] = {0};

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        string s;
        cin>>s;
        timer[f(s)%1440] = 1;
        timer[(f(s)%1440) + 1440] = 1;
    }
    
    int best = 0;
    int temp = 0;
    for (int i = 0; i<2880; i++)
    {
        if (timer[i]==0) temp++;
        else {best = max(best, temp); temp = 0;}
    }

    cout<<s(best);
}