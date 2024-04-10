Program arsijo;
Var n, m, i: longint;
        ar: array [0..400000] of longint;
        bol: array [1..400000] of boolean;
        a, b, c, d, max, pos1, pos2: int64;
        boll: boolean;

procedure sort(l,r: longint);
      var
         i,j,x,y,t: longint;
         bo: boolean;
      begin
         i:=l;
         j:=r;
         t:=l+random(r-l);
         x := ar[t];
         repeat
           while (ar[i]<x){ or ( (ar[i] = x) and not(bol[i]) and (bol[t]))} do
            inc(i);
           while (x<ar[j]){ or ( (ar[j] = x) and not(bol[j]) and (bol[t]))} do
            dec( j );
           if not(i>j) then
             begin
                y:=ar[i];
                ar[i]:=ar[j];
                ar[j]:=y;
                bo:=bol[i];
                bol[i]:=bol[j];
                bol[j]:=bo;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
Begin
    Read(n);
    for i:=1 to n do
        Read(ar[i]);
    for i:=1 to n do
        bol[i] := true;
    Read(m);
    for i:=1 to m do
        Read(ar[i+n]);
    for i:=1 to m do
        bol[i+n] := false;
    sort(1, n+m);
    a := n * 3;
    b := m * 3;
    max := a - b;
    c := a;
    d := b;
    for i:=1 to (n+m) do
    begin
        if ar[i] = ar[i+1] then
        begin
            if bol[i] then
                dec(a) else
            dec(b);
            continue;
        end;
            if bol[i] then
                dec(a) else
                dec(b);
            if ( (a - b) > max) then
            begin
                max := a - b;
                c := a;
                d := b;
            end;
    end;

    WriteLn(c, ':', d);
End.