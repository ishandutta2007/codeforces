#include <bits/stdc++.h>
using namespace std;

template<typename T> T read(T &x)
{
    int f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (x = 0; isdigit(ch); ch = getchar())
        x = 10 * x + ch - '0';
    return x *= f;
}
template<typename T> void write(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static char s[20];
    int top = 0;
    for (; x; x /= 10)
        s[++top] = x % 10 + '0';
    while (top)
        putchar(s[top--]);
}

char _mem[250000000];
int _pos;

inline void* operator new(size_t x)
{
	_pos += x;
	return _mem + _pos - x;
}
inline void operator delete(void* x)
{
	
}

int main() {
	int n;
	read(n);
	
	set<int> s;
	for(int i = 0; i < n; ++i)
	{
		int x;
		read(x);
		s.insert(x);
	}
	
	while(true)
	{
		int x = *s.rbegin();
		x >>= 1;
		while(x > 0)
		{
			if(s.find(x) == s.end())
			{
				break;
			}
			x >>= 1;
		}
		if(x == 0)
		{
			break;
		}
		s.erase(--s.end());
		s.insert(x);
	}
	
	for(int i : s)
		write(i), putchar(' ');
	
	return 0;
}