var a,b:int64;i:longint;
  z:array[1..10000] of int64;
procedure rec(k:longint);
Begin
  if z[k-1]=b then
  Begin
    writeln('YES');
    writeln(k-1);
     for I:=1 to k-1 do
     write(z[i], ' ');
     halt(0);
  end else  if z[k-1]<b then
  Begin
        z[k]:=z[k-1]*2;
        rec(k+1);
        z[k]:=z[k-1]*10+1;
        rec(k+1);

  end;
end;
Begin
  readln(a,b);
  z[1]:=a;
  rec(2);
  writeln('NO');
end.