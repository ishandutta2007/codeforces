Program arsijo;
Var n, i, pos, a, b, x, ans: longint;
Begin
        Read(n, x);
        pos := 1;
        ans := 0;
        for i := 1 to n do
        begin
                Read(a, b);
                while (pos + x) <= a do
                        inc(pos, x);
                inc(ans, b - pos + 1);
                pos := b+1;
        end;
        WriteLn(ans);
End.