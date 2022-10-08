#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::string s, sub;
    std::cin >> s >> sub;

    std::vector<int> cnt(10), subcnt(10);
    for (char c : s)
    {
        cnt[c - '0'] ++;
    }

    for (char c : sub)
    {
        subcnt[c - '0'] ++;
        cnt[c - '0'] --;
    }

    int length = 0;
    if (s.size() <= 10)
    {
        length = 1;
    }
    else if (12 <= s.size() && s.size() <= 101)
    {
        length = 2;
    }
    else if (103 <= s.size() && s.size() <= 1002)
    {
        length = 3;
    }
    else if (1004 <= s.size() && s.size() <= 10003)
    {
        length = 4;
    }
    else if (10005 <= s.size() && s.size() <= 100004)
    {
        length = 5;
    }
    else if (100006 <= s.size() && s.size() <= 1000005)
    {
        length = 6;
    }

    {
        int t = s.size() - length;
        while (t)
        {
            cnt[t % 10] --;
            t /= 10;
        }
    }

    if (s.size() - length == 1 && sub == "0")
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::stringstream ss1, ss2;
    if (sub[0] > '0')
    {
        ss1 << sub;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                ss1 << i;
            }
        }
    }

    {
        bool nonzero = false;
        for (int i = 1; i < 10; i++)
        {
            if (cnt[i] > 0)
            {
                nonzero = true;
                ss2 << i;
                cnt[i] --;
                break;
            }
        }
        if (nonzero)
        {
            bool printed = false;
            for (int i = 0; i < 10; i++)
            {
                if (!printed)
                {
                    bool smaller=true;
                    for (int j = 0; smaller && j < sub.size(); j++)
                    {
                        if (sub[j] - '0' < i)
                        {
                            break;
                        }
                        if (sub[j] - '0' > i)
                        {
                            smaller = false;
                            break;
                        }
                    }
                    if (smaller)
                    {
                        ss2 << sub;
                        printed = true;
                    }
                }
                for (int j = 0; j < cnt[i]; j++)
                {
                    ss2 << i;
                }
            }
        }
    }

    if (ss2.str() == "" || ss1.str() < ss2.str() && ss1.str() != "")
    {
        std::cout << ss1.str() << std::endl;
    }
    else
    {
        std::cout << ss2.str() << std::endl;
    }

    return 0;
}