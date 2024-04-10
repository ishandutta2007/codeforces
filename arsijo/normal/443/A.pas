Program arsijo;
Var a, b, n, i, h: longint;
        ar: array ['a'..'z'] of boolean;
        s: ansistring;
Begin
    ReadLn(s);
    a := 0;
    for i:=1 to length(s) div 3 do
    begin
        if not(ar[s[i*3-1]]) then
        begin
            inc(a);
            ar[s[i*3-1]] := true;
        end;
    end;
    WriteLn(a)
End.