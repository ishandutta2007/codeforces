Program arsijo;
Var s1, s2, s: String;
        i, n: longint;
        ar: array ['A'..'Z'] of longint;
        c: char;
Begin
    ReadLn(s1);
    //for i:=1 to length(s) do
      //  inc(ar[s[i]]);
    ReadLn(s2);
    //for i:=1 to length(s) do
      //  inc(ar[s[i]]);
    ReadLn(s);
    for i:=1 to length(s) do
        inc(ar[s[i]]);
    for i:=1 to length(s1) do
    begin
        if ar[s1[i]] = 0 then
        begin
            WriteLn('NO');
            exit;
        end else
                dec(ar[s1[i]]);
    end;
    for i:=1 to length(s2) do
    begin
        if ar[s2[i]] < 0 then
        begin
            WriteLn('NO');
            exit;
        end else
                dec(ar[s2[i]]);
    end;
    for c := 'A' to 'Z' do
        if ar[c] <> 0 then
        begin
            WriteLn('NO');
            exit;
        end;
    WriteLn('YES');
End.