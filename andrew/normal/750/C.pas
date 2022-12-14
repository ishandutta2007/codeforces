var a,d:array[1..200000] of int64;
n,i,kl:longint;
l,r:int64;
inf:int64;
begin
  readln(n);
  for i:=1 to n do
    readln(a[i],d[i]);
  inf:=20050000;
  r:=inf;
  l:=-inf;
  for i:=1 to n do
    begin
      if d[i]=1 then begin
                       if l<1900 then l:=1900;
                       if r<1900 then begin
                                        writeln('Impossible');
                                        halt;
                                      end;
                     end
        else begin
               kl:=1;
               if r>=1900 then r:=1899;
               if l>1899 then begin
                                writeln('Impossible');
                                halt;
                              end;
             end;
      r:=r+a[i];
      l:=l+a[i];
    end;


  if kl=0 then writeln('Infinity')
    else writeln(r);
end.