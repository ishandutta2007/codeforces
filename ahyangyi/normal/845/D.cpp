#include <iostream>
#include <array>

using namespace std;

inline void update(int& value, int new_value)
{
    if (value == -1 || new_value < value)
    {
        value = new_value;
    }
}

int main()
{
    const int maxS = 301;

    int n;
    cin >> n;
    typedef array<array<int, maxS>, 2> state_t;
    state_t state;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < maxS; ++j)
        {
            if (i == 0 && j == 0)
            {
                state[i][j] = 0;
            }
            else
            {
                state[i][j] = -1;
            }
        }
    }

    int current_speed = -1;
    for (int it = 0; it < n; ++it)
    {
        int t, s;
        cin >> t;
        if (t == 1 || t == 3)
        {
            cin >> s;
        }
        if (t == 1)
        {
            current_speed = s;
        }
 
        state_t new_state;
        
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < maxS; ++j)
            {
                new_state[i][j] = -1;
            }
        }

        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < maxS; ++j)
            {
                if (state[i][j] != -1)
                {
                    switch (t)
                    {
                        case 1:
                            if (current_speed <= j || j == 0)
                            {
                                update(new_state[i][j], state[i][j]);
                            }
                            break;
                        case 2:
                            if (i == 0)
                            {
                                update(new_state[i][j], state[i][j]);
                            }
                            break;
                        case 3:
                            update(new_state[i][j], state[i][j] + 1);
                            if (current_speed <= s)
                            {
                                update(new_state[i][s], state[i][j]);
                            }
                            break;
                        case 4:
                            update(new_state[i][j], state[i][j] + 1);
                            update(new_state[0][j], state[i][j]);
                            break;
                        case 5:
                            update(new_state[i][j], state[i][j] + 1);
                            update(new_state[i][0], state[i][j]);
                            break;
                        case 6:
                            update(new_state[i][j], state[i][j] + 1);
                            update(new_state[1][j], state[i][j]);
                            break;
                    }
                }
            }
        }
        state = new_state;
    }
    int ans = -1;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < maxS; ++j)
        {
            if (state[i][j] != -1)
            {
                update(ans, state[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}