Program arsijo;
Var a, i: longint;
        ar: array ['a'..'z'] of boolean;
        s: string;
Begin
    ReadLn(s);
    a := 0;
    for i:=1 to length(s) do
        if not(ar[s[i]]) then
        begin
            ar[s[i]] := true;
            inc(a);
        end;
    if a mod 2 = 0 then
        WriteLn('CHAT WITH HER!') else
        WriteLn('IGNORE HIM!');
End.