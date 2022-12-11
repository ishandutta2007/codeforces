var a,b:array[1..200000]of longint;
    n,m,l,r,o,i:longint;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  read(b[i]);
  if a[b[i]]=0 then inc(o);
  inc(a[b[i]]);
 end;
 if o<m then begin writeln('-1 -1');halt(0);end;
 l:=1;r:=n;
 while (l<=n)and(o>=m) do begin dec(a[b[l]]);if a[b[l]]<=0 then dec(o);inc(l);end;dec(l);inc(o);
 while (r>=1)and(o>=m) do begin dec(a[b[r]]);if a[b[r]]<=0 then dec(o);dec(r);end;inc(r);inc(o);
 writeln(l,' ',r);
end.