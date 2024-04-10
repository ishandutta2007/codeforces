Program arsijo;
Var n, m, i, j: longint;
        s: String;
        ar: array [1..100, 1..100] of char;
Begin
    ReadLn(n, m);
    for i:=1 to n do
    begin
        ReadLN(s);
        for j:=1 to m do
                ar[i, j] := s[j];
    end;
    for i:=1 to n do
    begin
        for j:=1 to m do
                if ar[i, j] = '-' then
                        Write('-') else
                if ((i+j) mod 2) = 0 then Write('B') else
                        Write('W');
        WriteLn;
    end;
End.