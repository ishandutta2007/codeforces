#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m ;
	char c ;
	cin>>n>>m>>c ;

	std::vector<std::vector<char> > A(n, std::vector<char> (m,'1')) ;

	std::vector<pair<int,int> > V;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>A[i][j];	
			if(A[i][j]==c)
			{
				V.push_back(make_pair(i,j));
			}		
		}
	}
    //cout<<V[0].first<<" "<<V[0].second<<endl;
	unordered_set<char> S;
	S.insert(c);
	S.insert('.');
	int I,J,count=0;

	for (int i = 0; i < V.size(); ++i)
	{
		I=V[i].first;
		J=V[i].second;
		if( ((I+1)<n) && (S.find(A[I+1][J])==S.end()) )
		{	
			count++;
			S.insert(A[I+1][J]);
		} 
		if ( ((I-1)>=0) && (S.find(A[I-1][J])==S.end()) )
		{
			count++;
			S.insert(A[I-1][J]);
		}  
		if ( ((J+1)<m) && (S.find(A[I][J+1])==S.end()) )
		{
			count++;
			S.insert(A[I][J+1] );
		}
		if (  ((J-1)>=0) && (S.find(A[I][J-1])==S.end()) )
		{
			count++;
			S.insert(A[I][J-1]);
		}
	}
 	
 	cout<<count;
 	return 0;
 }