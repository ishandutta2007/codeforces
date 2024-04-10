Program arsijo;
Var n, m, i, j, l, k, r, x, y:longint;
begin
        Readln(n, m, x, y);
        l := 1;
        r := (n+m) * 2;
        while (l < r) do
        begin
                k := (l+r) shr 1;
                if (n <= k - (k div x)) and (m <= k - (k div y))
                and (n + m <= k - (k div (x*y))) then
                        r := k else
                        l := k+1;
        end;
        WriteLn(r);
end.