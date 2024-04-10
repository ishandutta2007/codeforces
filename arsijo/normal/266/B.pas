Program arsijo;
uses math;
Var s: String;
        i, j, t, n: longint;
        b: boolean;
Procedure change(index: longint);
Begin
        s[index] := 'B';
        s[index-1] := 'G';
End;
Begin
    ReadLn(n, t);
    ReadLn(s);
    for i:=2 to min(length(s), t+1) do
    begin
        b := false;
        for j:=1 to length(s) do
        begin
            if b then
            begin
                b := false;
                continue;
            end;
            if (s[j] = 'G') and (s[j-1] = 'B') then
            begin
                change(j);
                b := true;
            end;
        end;
    end;
    WriteLn(s);
End.