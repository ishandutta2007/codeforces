Program zadacha;
Var s1, s2, s3, s, ans: String;
    c: char;
    a, i, j: longint;
    b: boolean;
Begin
    s1 := 'qwertyuiop';
    s2 := 'asdfghjkl;';
    s3 := 'zxcvbnm,./';
    Readln(c);
    Readln(s);
    ans := '';
    if c = 'L' then a := 1 else a := -1;
    for i:=1 to Length(s) do
    begin
        b := false;
        for j:=1 to Length(s1) do
        begin
            if s[i] = s1[j] then
            begin
                ans := ans + s1[j+a];
                b := true;
                break;
            end;
        end;
        if not(b) then for j:=1 to Length(s2) do
        begin
            if s[i] = s2[j] then
            begin
                ans := ans + s2[j+a];
                b := true;
                break;
            end;
        end;
        if not(b) then for j:=1 to Length(s3) do
        begin
            if s[i] = s3[j] then
            begin
                ans := ans + s3[j+a];
                break;
            end;
        end;
    end;
    WriteLn(ans);
    Read(i);
End.