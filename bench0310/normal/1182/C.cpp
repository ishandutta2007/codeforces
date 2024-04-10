#include <bits/stdc++.h>

using namespace std;
const int N=100005;

string s[N];
int vowel_cnt[N];

char last_vowel(string a)
{
    for(int i=(int)a.size()-1;i>=0;i--)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') return a[i];
    }
    return '?';
}

int vowel_count(string a)
{
    int res=0;
    for(int i=(int)a.size()-1;i>=0;i--)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') res++;
    }
    return res;
}

bool comp(pair<char,int> a,pair<char,int> b)
{
    return (bool)(vowel_cnt[a.second]<vowel_cnt[b.second]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<char,int> > v;
	for(int i=0;i<n;i++)
    {
        cin >> s[i];
        vowel_cnt[i]=vowel_count(s[i]);
        v.push_back(make_pair(last_vowel(s[i]),i));
    }
    sort(v.begin(),v.end(),comp);
    vector<pair<char,int> > now;
    vector<pair<int,int> > one,two; //one-equal vowels, two-different
    int idx=0,sz=vowel_cnt[v[0].second];
    while(1)
    {
        while(idx<n&&vowel_cnt[v[idx].second]==sz)
        {
            now.push_back(v[idx]);
            idx++;
        }
        sort(now.begin(),now.end());
        vector<bool> vis(now.size(),0);
        for(int i=0;i<(int)now.size()-1;i++)
        {
            if(vis[i]) continue;
            if(now[i].first==now[i+1].first)
            {
                one.push_back(make_pair(now[i].second,now[i+1].second));
                vis[i]=1;
                vis[i+1]=1;
            }
        }
        vector<int> temp;
        for(int i=0;i<(int)now.size();i++)
        {
            if(vis[i]==0) temp.push_back(now[i].second);
        }
        for(int i=0;i<(int)temp.size()-1;i+=2)
        {
            two.push_back(make_pair(temp[i],temp[i+1]));
        }
        now.clear();
        if(idx>=n) break;
        sz=vowel_cnt[v[idx].second];
    }
    /*cout << "one: " << endl;
    for(int i=0;i<(int)one.size();i++) cout << s[one[i].first] << " " << s[one[i].second] << endl;
    cout << endl;
    cout << "two: " << endl;
    for(int i=0;i<(int)two.size();i++) cout << s[two[i].first] << " " << s[two[i].second] << endl;*/
    vector<pair<int,int> > resone,restwo;
    int idone=0,idtwo=0;
    int szone=one.size(),sztwo=two.size();
    while(idone<szone)
    {
        if(idtwo<sztwo)
        {
            resone.push_back(make_pair(two[idtwo].first,one[idone].first));
            restwo.push_back(make_pair(two[idtwo].second,one[idone].second));
            idone++;
            idtwo++;
        }
        else
        {
            if(idone+1<szone)
            {
                resone.push_back(make_pair(one[idone].first,one[idone+1].first));
                restwo.push_back(make_pair(one[idone].second,one[idone+1].second));
                idone+=2;
            }
            else idone++;
        }
    }
    cout << resone.size() << endl;
    for(int i=0;i<(int)resone.size();i++)
    {
        cout << s[resone[i].first] << " " << s[resone[i].second] << endl;
        cout << s[restwo[i].first] << " " << s[restwo[i].second] << endl;
    }
	return 0;
}