Program arsijo;
Var s: ansiString;
        i, a, b, c: longint;
        bol: boolean;
Begin
    i := 1;
    ReadLn(s);
    while i <= length(s) do
    begin
        if (i + 2 <= length(s)) and (s[i] = 'W') and (s[i+1] = 'U') and (s[i+2] = 'B') then
        begin
                if bol then
                        Write(' ');
                bol := false;
                inc(i, 3);
        end else
        begin
            bol := true;
            Write(s[i]);
            inc(i);
        end;
    end;

End.