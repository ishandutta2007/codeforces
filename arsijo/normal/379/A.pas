Program arsijo;
Var a, b, c, r, t, u: longint;
Begin
        Read(a, b);
        r := a;
        u := 0;
        while a div b <> 0 do
        begin
            inc(r, a div b);
            u := a mod b;
            a := a div b;
            inc(a, u);
        end;
        WriteLn(r);
End.