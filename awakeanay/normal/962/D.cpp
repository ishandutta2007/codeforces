#include <iostream>
#include <queue>

struct num
{
	long long value;
	int pos;
};

inline bool operator <(num a, num b)
{
	if(a.value > b.value)
		return true;
	
	if(a.value == b.value && a.pos > b.pos)
		return true;
		
	return false;
}

inline bool operator ==(num a, num b)
{
	return (a.value == b.value) && (a.pos == b.pos);
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin >> N;
	
	num zero = {-1, -1};
	
	std::priority_queue<num> pq;
	
	long long A[N];
	
	for(int i = 0; i < N; i++)
	{
		std::cin >> A[i];
		pq.push({A[i], i});
	}
	
	num l = zero, r = zero;
	int answer = 0;
	while(!pq.empty())
	{
		if(l == zero)
		{
			l = pq.top(); pq.pop();
		}
		
		if(pq.empty())
			break;
		
		r = pq.top(); pq.pop();
		
		//std::cout << "checking: " << l.value << " " << l.pos << " " << r.value << " " << r.pos << std::endl;
		
		if(l.value != r.value)
		{
			l = r;
			r = zero;
		}
		else
		{
			A[r.pos] = 2*l.value;
			A[l.pos] = -1;
			pq.push({2*l.value, r.pos});
			l = r = zero;
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		if(A[i] != -1)
			answer++;
	}
	std::cout << answer << std::endl;
	for(int i = 0; i < N; i++)
	{
		if(A[i] != -1)
			std::cout << A[i] << " ";
	}
	
	return 0;
}