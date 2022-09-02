#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 998244353;

int n, m;

vector<vector<int>> solve(vector<pair<int, int>> G)
{
    vector<vector<int>> answer;
    vector<vector<int>> board;
    for (int i = 0; i<n; i++) 
    {
        vector<int> temp(n, -1);
        board.push_back(temp);
    }
    
    for (int i = 0; i<m; i++) board[G[i].first][G[i].second] = i;
    int full = 0;
    for (int j = 0; j<n; j++)
    if (board[0][j]!=-1)
    {
        int j1 = j;
        full++;
        while (j1>=1&&board[0][j1-1]==-1) 
        {
            swap(board[0][j1], board[0][j1-1]); 
            vector<int> t(4);
            t[0] = 0;
            t[1] = j1;
            t[2] = 0;
            t[3] = j1-1;
            j1--;
            answer.push_back(t);
        }
    }
    
    /*for (int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++) cout<<board[i][j]<<' ';
        cout<<endl;
    }*/
    
    for (int i = 1; i<=n-1; i++)
    {
        for (int j = n-1; j>=0; j--)
        if (board[i][j]!=-1)
        {
            int i1 = i;
            int j1 = j;
            while (j1<full+1&&board[i1][j1+1]==-1)
            {
            swap(board[i1][j1], board[i1][j1+1]); 
            vector<int> t(4);
            t[0] = i1;
            t[1] = j1;
            t[2] = i1;
            t[3] = j1+1;
            answer.push_back(t);
            j1++;
            }
            while (i1>0&&board[i1-1][j1]==-1)
            {
            swap(board[i1][j1], board[i1-1][j1]); 
            vector<int> t(4);
            t[0] = i1;
            t[1] = j1;
            t[2] = i1-1;
            t[3] = j1;
            answer.push_back(t);
            i1--;
            }
            while (j1>0&&board[0][j1-1]==-1)
            {
            swap(board[0][j1], board[0][j1-1]); 
            vector<int> t(4);
            t[0] = 0;
            t[1] = j1;
            t[2] = 0;
            t[3] = j1-1;
            answer.push_back(t);
            j1--;
            }
            full++;
        }
    }
    
    
    int kek = 0;
    
    
   
    if (n==2&&m==2)
    {
        if (board[0][0]==0)
        {
            vector<int> t(4);
            t[0] = 0;
            t[1] = 0;
            t[2] = 1;
            t[3] = 0;
            answer.push_back(t);
            t[1] = 1;
            t[3] = 1;
            answer.push_back(t);
        }
        else
        {
            vector<int> t(4);
            t[0] = 0;
            t[1] = 0;
            t[2] = 1;
            t[3] = 0;
            answer.push_back(t);
            t[0] = 1;
            t[1] = 0;
            t[2] = 1;
            t[3] = 1;
            answer.push_back(t);
            t[0] = 0;
            t[1] = 1;
            t[2] = 0;
            t[3] = 0;
            answer.push_back(t);
            t[0] = 0;
            t[1] = 0;
            t[2] = 1;
            t[3] = 0;
            answer.push_back(t);
        }
    }
    else
    for (int j = 0; j<n; j++)
    {
        if (board[0][j]!=-1)
        {
            int k = board[0][j];
            int i1 = 0;
            int j1 = j;
            int bad = 1;
            if (n==2) bad = 0;
            while (i1!=bad)
            {
                swap(board[i1][j1], board[i1+1][j1]);
                vector<int> t(4);
                t[0] = i1;
                t[1] = j1;
                t[2] = i1+1;
                t[3] = j1;
                i1++;
                answer.push_back(t);
            }
            while (j1!=k)
            {
                int cool = 1;
                if (j1>k) cool = -1;
                swap(board[i1][j1], board[i1][j1+cool]);
                vector<int> t(4);
                t[0] = i1;
                t[1] = j1;
                t[2] = i1;
                t[3] = j1+cool;
                j1 = j1+cool;
                answer.push_back(t);
            }

            swap(board[i1][j1], board[i1+1][j1]);
            vector<int> t(4);
            t[0] = i1;
            t[1] = j1;
            t[2] = i1+1;
            t[3] = j1;
            i1++;
            answer.push_back(t);
        }
    }
   return answer; 
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    if (n==1) {cout<<0; return 0;}
    vector<pair<int, int>> G1(m), G2(m);
    for (int i = 0; i<m; i++) {cin>>G1[i].first>>G1[i].second; G1[i].first--; G1[i].second--;}
    for (int i = 0; i<m; i++) {cin>>G2[i].first>>G2[i].second; G2[i].first--; G2[i].second--;}
    vector<vector<int>> answer1 = solve(G1);
    vector<vector<int>> answer2 = solve(G2);
    cout<<int(answer1.size())+int(answer2.size())<<endl;
    for (int i = 0; i<answer1.size(); i++)
    {
        cout<<answer1[i][0]+1<<' '<<answer1[i][1]+1<<' '<<answer1[i][2]+1<<' '<<answer1[i][3]+1<<endl;
    }
    for (int i = int(answer2.size())-1; i>=0; i--)
    {
        cout<<answer2[i][2]+1<<' '<<answer2[i][3]+1<<' '<<answer2[i][0]+1<<' '<<answer2[i][1]+1<<endl;
    }
}