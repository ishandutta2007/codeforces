Program arsijo;
Var n, k, l, r, sall, sk, a, b, c, d, i: longint;
Begin
        ReadLn(n, k, l, r, sall, sk);
        a := sk mod k;
        b := sk div k;
        for i:=1 to a do
                Write(b + 1, ' ');
        for i:=1 to k - a do
                Write(b, ' ');
        a := sall - sk;
        b := n - k;
        if b = 0 then
                exit;
        c := a mod b;
        d := a div b;
        for i:=1 to c do
                Write(d + 1, ' ');
        for i:=1 to (b-c) do
                Write(d, ' ');
End.