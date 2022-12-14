var
 a:array[0..100000]of longint;
 v:array[1..1000,1..1000]of longint;
 x,i,j,n,m,k,sc,ch1,ch2:longint;
 s:ansistring;
begin
 readln(s);
 k:=1;
 for i:=1 to length(s)-1 do if(s[i]='V')and(s[i+1]='K')and(a[i]=0)and(a[i+1]=0)then
 begin
  inc(sc);
  a[i]:=-1;
  a[i+1]:=-1;
 end;
 for i:=1 to length(s)-1 do if(s[i]='V')and(s[i+1]='V')and(a[i+1]=0)then begin inc(sc); break; end
  else if(s[i]='K')and(s[i+1]='K')and(a[i]=0)then begin inc(sc); break; end;
 writeln(sc);
end.