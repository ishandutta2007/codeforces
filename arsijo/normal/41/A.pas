Program arsijo;
Var s1, s2: String;
        i: longint;
Begin
    ReadLn(s1);
    ReadLn(s2);
    for i:=1 to length(s1) do
    begin
        if (s1[i] <> s2[length(s1) - i + 1]) then
        begin
            WriteLn('NO');
            exit;
        end;
    end;
    WriteLn('YES');
End.