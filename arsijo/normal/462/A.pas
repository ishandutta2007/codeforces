Program arsijo;
Var n, i, j, a: longint;
        c1, c2: char;
        s: String;
        ar: array [0..101, 0..101] of char;
Begin
        ReadLn(n);
        c1 := 'x';
        c2 := 'o';
        for i:=1 to n do
        begin
                ReadLn(s);
                for j:=1 to n do
                         ar[i, j] := s[j];
                ar[0, i] := c1;
                ar[i, 0] := c1;
                ar[n+1, i] := c1;
                ar[i, n+1] := c1;
        end;
        for i:=1 to n do
                for j:=1 to n do
                begin
                        a := 0;
                        if ar[i-1, j] = c2 then inc(a);
                        if ar[i+1, j] = c2 then inc(a);
                        if ar[i, j-1] = c2 then inc(a);
                        if ar[i, j+1] = c2 then inc(a);
                        if a mod 2 = 1 then
                        begin
                            WriteLn('NO');
                            exit;
                        end;
                end;
        WriteLn('YES');

End.