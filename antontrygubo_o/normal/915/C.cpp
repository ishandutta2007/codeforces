#include <bits/stdc++.h>

using namespace std;

bool C(vector<char> A, vector<char> B, int t)
{
    vector<char> answer;
    for (int i = 0; i<t; i++)
    {
        int j = 0; while ((A[j]!=B[i])&&(j<A.size())) j++;
        if (j==A.size()) return false;
        answer.push_back(B[i]);
        A.erase(A.begin()+j);
    }
    int k = 0;
    if (t<B.size())
    {
    if (A[0]>=B[t]) return false;
    while ((A[k]<B[t])&&(k<A.size())) k++;
    answer.push_back(A[k-1]);
    A.erase(A.begin()+k-1);
    for (int i = A.size()-1; i>=0; i--) answer.push_back(A[i]);
    }
    for (int i = 0; i<answer.size(); i++) cout<<answer[i];
    return true;
    
}

int main() 
{
string a;
string b;
cin>>a>>b;
int a1 = a.length();
int b1 = b.length();
vector<char> A;
vector<char> B;
for (int i = 0; i<a1; i++) A.push_back(a[i]);
for (int i = 0; i<b1; i++) B.push_back(b[i]);

sort (A.begin(), A.end());
if (b1>a1) {for (int i = a1-1; i>=0; i--) cout<<A[i]; return 0;}

int indicator = a1;
bool ind = false;
while (!ind)
{
    //cout<<indicator<<endl;
    ind = C(A, B, indicator);
    indicator--;
}



}