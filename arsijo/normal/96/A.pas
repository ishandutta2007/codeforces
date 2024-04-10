Program arsijo;
Var s: String;
Function check: String;
Var i, b: longint;
        c, last: char;
Begin
        b := 1;
        last := s[1];
        for i:=2 to length(s) do
        begin
                if last = s[i] then
                        inc(b) else
                        begin
                            b := 1;
                            last := s[i];
                        end;
                if b = 7 then exit('YES');
        end;
        exit('NO');

End;
Begin
        ReadLn(s);
        WriteLn(check);
End.