var a:array[1..100]of boolean;
    b:array[1..100]of record a,b,c,d:longint;end;
    i,f,l,n,m,k,o,p:longint;s:string;
    log1,log2:boolean;
begin
 assign(input,'input.txt');reset(input);
 assign(output,'output.txt');rewrite(output);
 readln(n,m);n:=n-m;
 for i:=1 to m do begin read(k);a[k]:=true;end;
 readln(o);
 for i:=1 to o do
 begin
  readln(s);
  readln(k);
  for f:=1 to k do
  begin
   read(l);
   if l=0 then inc(b[i].a) else if a[l] then inc(b[i].b) else inc(b[i].c);
  end;
  readln;
  {if b[i].a+b[i].b>m then b[i].a:=m-b[i].b;}
  if b[i].c+b[i].a>n then begin b[i].b:=b[i].b+b[i].a-n+b[i].c;b[i].a:=n-b[i].c;end;
  b[i].d:=b[i].a+b[i].b;if b[i].d>m then b[i].d:=m;
 end;
 for i:=1 to o do
 begin
  log1:=false;log2:=false;
  for f:=1 to o do
  begin
   if (i<>f)and(b[i].b<b[f].d) then log1:=true;
   if (i<>f)and(b[i].d<b[f].b) then log2:=true;
  end;
  if (log1)and(log2) then writeln(1) else if not(log1) then writeln(0) else writeln(2);
 end;
 close(input);close(output);
end.