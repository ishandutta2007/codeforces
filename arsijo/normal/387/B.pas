Program arsijo;
Var i, n, j, c, m: longint;
        a, b: array [1..3000] of longint;

procedure sorta(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[l+random(r-l)];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
            dec( j );
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sorta(l,j);
         if i<r then
           sorta(i,r);
      end;

procedure sortb(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=b[l+random(r-l)];
         repeat
           while b[i]>x do
            inc(i);
           while x>b[j] do
            dec( j );
           if not(i>j) then
             begin
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sortb(l,j);
         if i<r then
           sortb(i,r);
      end;

Begin
        Read(n, m);
        for i:=1 to n do
                Read(a[i]);
        for i:=1 to m do
                Read(b[i]);
        sorta(1, n);
        sortb(1, m);
        c := 0;
        j := 1;
        for i:= 1 to n do
        begin
                if j > m then
                        break;
                if a[i] <= b[j] then
                begin
                    inc(c);
                    inc(j);
                end;
        end;
        WriteLn(n-c);
End.