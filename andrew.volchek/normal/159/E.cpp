#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define pair < long, long > pp;
#define ull unsigned long long

struct cube
{
	unsigned long c;
	unsigned long s;
	unsigned long i;
};

bool comp(cube a,cube b)
{
	if(a.c > b.c || (a.c == b.c && a.s > b.s))
		return true;
	return false;
}



int main()
{
	long N;
	cube *A = new cube[100000];

	cin >> N;
	cin.ignore();

	//N = 100000;
	


	cube c;

	for(long i=0;i<N;i++)
	{
		cin >> c.c >> c.s;
		c.i = i+1;
		cin.ignore();
		c.i = i+1;
		/*c.s = rand()*723;
		c.c = rand()*4564;*/
		A[i] = c;
	}
	
	

	sort(A,A+N,comp);

	vector < ull >  *B = new vector < ull >[100000];
	long  *S = new long[100000];
	long p = 0;
	long len = 1;
	unsigned long curr_c = 0;;
	
	ull sum = 0;
	long groups_count = 0;
	

	while(p < N)
	{
		if(curr_c == A[p].c)
		{
			sum += A[p].s;
			B[groups_count-1].push_back(sum);
			p++;
		}
		else
		{
			groups_count++;
			S[groups_count-1] = p;
			sum = 0;
			curr_c = A[p].c;
		}
	}
	set < long > L;
	for(long i=0;i<groups_count;i++)
	{
		L.insert(B[i].size());
	}
	//vector < long >::iterator it = unique(L.begin(),L.end());
	//L.resize(it-L.begin());
	ull max_sum = 0;
	ull max_count;
	
	ull max1,max2,j1,j2,j3,j4;
	for (set <long >::iterator i=L.begin();i!=L.end();i++)
	{
		max1 = 0;
		max2 = 0;
		j1 = -1;
		j2 = -1;
		for (long j=0;j<groups_count;j++)
		{
			if(B[j].size()-1>=*i)
				sum = B[j][*i];
			else if(B[j].size()==*i)
				sum = B[j][*i-1];
			else
				sum = 0;

			if(sum>max1)
			{
				if(max1>max2)
				{
					max2 = max1;
					j2 = j1;
				}
				max1 = sum;
				j1 = j;
			}
			else if(sum>max2)
			{
				max2 = sum;
				j2 = j;
			}

		}
		if(max_sum<(max1+max2)&&(j1!=-1&&j2!=-1))
		{
			max_sum = (max1+max2);
			j3 = j1;
			j4 = j2;
		}
	}
	if(B[j3].size()==B[j4].size())
		max_count = B[j3].size()*2;
	else
		max_count = min(B[j3].size(),B[j4].size())*2 + 1;

	long s1 = S[j3];
	long s2 = S[j4];
	if(B[j4].size()<B[j3].size())
		swap(s1,s2);

	

	cout << max_sum << '\n';
	cout << max_count << '\n';
	

	for(long i=0;i<max_count;i++)
	{
		if(i%2)
		{
			cout << A[i/2+s1].i << " ";
		}
		else
		{
			cout << A[i/2+s2].i << " ";
		}
	}



	return 0;
}