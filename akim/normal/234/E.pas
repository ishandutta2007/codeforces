type team=record n:string;p:longint;b:boolean;end;
var a:array[1..64]of team;
    z:team;q:char;n,f,x,y,m,i,l,u,b,c,p:longint;
begin
 assign(input,'input.txt');reset(input);
 assign(output,'output.txt');rewrite(output);
 readln(n);
 readln(x,u,b,c);
 for i:=1 to n do
 begin
  readln(a[i].n);
  l:=pos(' ',a[i].n);
  val(copy(a[i].n,l+1,length(a[i].n)-l),a[i].p);
  delete(a[i].n,l,length(a[i].n)-l+1);
 end;
 for i:=1 to n-1 do
  for f:=i+1 to n do
   if a[i].p<a[f].p then begin
                      z:=a[i];
                      a[i]:=a[f];
                      a[f]:=z;
                     end;
 m:=n div 4;p:=m;q:='A';
 for f:=1 to n div 4 do
 begin
  writeln('Group ',q,':');inc(q);
  y:=(u*x+b)mod c;
  x:=y;
  y:=x mod m;i:=0;
  while y>=0 do begin inc(i);if not(a[i].b) then dec(y);end;a[i].b:=true;writeln(a[i].n);
  y:=(u*x+b)mod c;
  x:=y;
  y:=x mod m;i:=p;
  while y>=0 do begin inc(i);if not(a[i].b) then dec(y);end;a[i].b:=true;writeln(a[i].n);
  y:=(u*x+b)mod c;
  x:=y;
  y:=x mod m;i:=p*2;
  while y>=0 do begin inc(i);if not(a[i].b) then dec(y);end;a[i].b:=true;writeln(a[i].n);
  y:=(u*x+b)mod c;
  x:=y;
  y:=x mod m;i:=p*3;
  while y>=0 do begin inc(i);if not(a[i].b) then dec(y);end;a[i].b:=true;writeln(a[i].n);
   dec(m);
 end;
 close(input);close(output);
end.