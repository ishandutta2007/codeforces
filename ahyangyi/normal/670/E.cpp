#include <string>
#include <vector>
#include <iostream>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m, p;
    std::cin >> n >> m >> p;

    std::string s, o;
    std::cin >> s >> o;

    std::vector<int> next(n);
    std::vector<int> prev(n);
    std::vector<int> match(n);
    std::stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        next[i] = i==n-1? -1:i+1;
        prev[i] = i==0? -1:i-1;
        if (s[i] == '(')
        {
            stack.push(i);
        }
        else
        {
            int j = stack.top();
            stack.pop();

            match[j] = i;
            match[i] = j;
        }
    }

    int cursor = p - 1;
    for (int i = 0; i < m; i ++)
    {
        switch (o[i])
        {
            case 'L':
                if (prev[cursor] != -1)
                {
                    cursor = prev[cursor];
                }
                break;
            case 'R':
                if (next[cursor] != -1)
                {
                    cursor = next[cursor];
                }
                break;
            case 'D':
                {
                    int one = cursor;
                    int other = match[cursor];
                    if (one > other)
                    {
                        std::swap(one, other);
                    }
                    if (prev[one] == -1 && next[other] == -1)
                    {
                        // Failure!
                    }
                    else
                    {
                        if (next[other] == -1)
                        {
                            cursor = prev[one];
                            next[cursor] = -1;
                        }
                        else
                        {
                            cursor = next[other];
                            prev[cursor] = prev[one];
                            if (prev[one] != -1)
                            {
                                next[prev[one]] = cursor;
                            }
                        }
                    }
                }
        }
    }

    {
        while (prev[cursor] != -1)
        {
            cursor = prev[cursor];
        }
        while (cursor != -1)
        {
            std::cout << s[cursor];
            cursor = next[cursor];
        }

        std::cout << std::endl;
    }
    
    return 0;
}